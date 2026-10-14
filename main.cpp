// Cube World Alpha - Satin Armor Mod
//
// The game files carry a complete satin armour set - chest, shoulder, glove
// and boot, five models each - that nothing in the binary ever loads. This mod
// makes the silk armour wear those models instead.
//
// Models only: the items keep their silk name, stats and material. Satin is not
// an item type anywhere in the game, so there is nothing else it could be.

// ---- build requirements -----------------------------------------------------
#include <stdint.h>   // UINTPTR_MAX - pointer width, checked portably

#if !defined(_WIN32)
#  error "Target must be Windows: this is a DLL injected into Cube.exe. Cross-compile, e.g. i686-w64-mingw32-g++."
#endif
#if UINTPTR_MAX != 0xFFFFFFFFu
#  error "Target must be 32-bit: Cube.exe is PE32."
#endif

#include <windows.h>


struct Mapping
{
    const char* from; // what is currently there
    const char* to;   // what we want it to be
};

// Satin does not have the extra variants like silk or any other armor type that
// is used by the game. Those variants are replaced with the base satin model.
static const Mapping MAPPINGS[] = {
    { "silk-chest1.cub",            "satin-chest1.cub" },
    { "silk-chest1-random1.cub",    "satin-chest1.cub" },
    { "silk-chest1-random2.cub",    "satin-chest1.cub" },
    { "silk-chest1-random3.cub",    "satin-chest1.cub" },
    { "silk-chest1-random4.cub",    "satin-chest1.cub" },
    { "silk-chest2.cub",            "satin-chest2.cub" },
    { "silk-chest2-random1.cub",    "satin-chest2.cub" },
    { "silk-chest2-random2.cub",    "satin-chest2.cub" },
    { "silk-chest2-random3.cub",    "satin-chest2.cub" },
    { "silk-chest2-random4.cub",    "satin-chest2.cub" },
    { "silk-chest3.cub",            "satin-chest3.cub" },
    { "silk-chest3-random1.cub",    "satin-chest3.cub" },
    { "silk-chest3-random2.cub",    "satin-chest3.cub" },
    { "silk-chest3-random3.cub",    "satin-chest3.cub" },
    { "silk-chest3-random4.cub",    "satin-chest3.cub" },
    { "silk-chest4.cub",            "satin-chest4.cub" },
    { "silk-chest4-random1.cub",    "satin-chest4.cub" },
    { "silk-chest4-random2.cub",    "satin-chest4.cub" },
    { "silk-chest4-random3.cub",    "satin-chest4.cub" },
    { "silk-chest4-random4.cub",    "satin-chest4.cub" },
    { "silk-chest5.cub",            "satin-chest5.cub" },
    { "silk-chest5-random1.cub",    "satin-chest5.cub" },
    { "silk-chest5-random2.cub",    "satin-chest5.cub" },
    { "silk-chest5-random3.cub",    "satin-chest5.cub" },
    { "silk-chest5-random4.cub",    "satin-chest5.cub" },
    { "silk-shoulder1.cub",         "satin-shoulder1.cub" },
    { "silk-shoulder1-random1.cub", "satin-shoulder1.cub" },
    { "silk-shoulder1-random2.cub", "satin-shoulder1.cub" },
    { "silk-shoulder1-random3.cub", "satin-shoulder1.cub" },
    { "silk-shoulder1-random4.cub", "satin-shoulder1.cub" },
    { "silk-shoulder2.cub",         "satin-shoulder2.cub" },
    { "silk-shoulder2-random1.cub", "satin-shoulder2.cub" },
    { "silk-shoulder2-random2.cub", "satin-shoulder2.cub" },
    { "silk-shoulder2-random3.cub", "satin-shoulder2.cub" },
    { "silk-shoulder2-random4.cub", "satin-shoulder2.cub" },
    { "silk-shoulder3.cub",         "satin-shoulder3.cub" },
    { "silk-shoulder3-random1.cub", "satin-shoulder3.cub" },
    { "silk-shoulder3-random2.cub", "satin-shoulder3.cub" },
    { "silk-shoulder3-random3.cub", "satin-shoulder3.cub" },
    { "silk-shoulder3-random4.cub", "satin-shoulder3.cub" },
    { "silk-shoulder4.cub",         "satin-shoulder4.cub" },
    { "silk-shoulder4-random1.cub", "satin-shoulder4.cub" },
    { "silk-shoulder4-random2.cub", "satin-shoulder4.cub" },
    { "silk-shoulder4-random3.cub", "satin-shoulder4.cub" },
    { "silk-shoulder4-random4.cub", "satin-shoulder4.cub" },
    { "silk-shoulder5.cub",         "satin-shoulder5.cub" },
    { "silk-shoulder5-random1.cub", "satin-shoulder5.cub" },
    { "silk-shoulder5-random2.cub", "satin-shoulder5.cub" },
    { "silk-shoulder5-random3.cub", "satin-shoulder5.cub" },
    { "silk-shoulder5-random4.cub", "satin-shoulder5.cub" },
    { "silk-hand1.cub",             "satin-glove1.cub" },
    { "silk-hand1-random1.cub",     "satin-glove1.cub" },
    { "silk-hand1-random2.cub",     "satin-glove1.cub" },
    { "silk-hand1-random3.cub",     "satin-glove1.cub" },
    { "silk-hand1-random4.cub",     "satin-glove1.cub" },
    { "silk-hand2.cub",             "satin-glove2.cub" },
    { "silk-hand2-random1.cub",     "satin-glove2.cub" },
    { "silk-hand2-random2.cub",     "satin-glove2.cub" },
    { "silk-hand2-random3.cub",     "satin-glove2.cub" },
    { "silk-hand2-random4.cub",     "satin-glove2.cub" },
    { "silk-hand3.cub",             "satin-glove3.cub" },
    { "silk-hand3-random1.cub",     "satin-glove3.cub" },
    { "silk-hand3-random2.cub",     "satin-glove3.cub" },
    { "silk-hand3-random3.cub",     "satin-glove3.cub" },
    { "silk-hand3-random4.cub",     "satin-glove3.cub" },
    { "silk-hand4.cub",             "satin-glove4.cub" },
    { "silk-hand4-random1.cub",     "satin-glove4.cub" },
    { "silk-hand4-random2.cub",     "satin-glove4.cub" },
    { "silk-hand4-random3.cub",     "satin-glove4.cub" },
    { "silk-hand4-random4.cub",     "satin-glove4.cub" },
    { "silk-hand5.cub",             "satin-glove5.cub" },
    { "silk-hand5-random1.cub",     "satin-glove5.cub" },
    { "silk-hand5-random2.cub",     "satin-glove5.cub" },
    { "silk-hand5-random3.cub",     "satin-glove5.cub" },
    { "silk-hand5-random4.cub",     "satin-glove5.cub" },
    { "silk-foot1.cub",             "satin-boot1.cub" },
    { "silk-foot1-random1.cub",     "satin-boot1.cub" },
    { "silk-foot1-random2.cub",     "satin-boot1.cub" },
    { "silk-foot1-random3.cub",     "satin-boot1.cub" },
    { "silk-foot1-random4.cub",     "satin-boot1.cub" },
    { "silk-foot2.cub",             "satin-boot2.cub" },
    { "silk-foot2-random1.cub",     "satin-boot2.cub" },
    { "silk-foot2-random2.cub",     "satin-boot2.cub" },
    { "silk-foot2-random3.cub",     "satin-boot2.cub" },
    { "silk-foot2-random4.cub",     "satin-boot2.cub" },
    { "silk-foot3.cub",             "satin-boot3.cub" },
    { "silk-foot3-random1.cub",     "satin-boot3.cub" },
    { "silk-foot3-random2.cub",     "satin-boot3.cub" },
    { "silk-foot3-random3.cub",     "satin-boot3.cub" },
    { "silk-foot3-random4.cub",     "satin-boot3.cub" },
    { "silk-foot4.cub",             "satin-boot4.cub" },
    { "silk-foot4-random1.cub",     "satin-boot4.cub" },
    { "silk-foot4-random2.cub",     "satin-boot4.cub" },
    { "silk-foot4-random3.cub",     "satin-boot4.cub" },
    { "silk-foot4-random4.cub",     "satin-boot4.cub" },
    { "silk-foot5.cub",             "satin-boot5.cub" },
    { "silk-foot5-random1.cub",     "satin-boot5.cub" },
    { "silk-foot5-random2.cub",     "satin-boot5.cub" },
    { "silk-foot5-random3.cub",     "satin-boot5.cub" },
    { "silk-foot5-random4.cub",     "satin-boot5.cub" },
};

static const uint32_t MAPPING_COUNT = sizeof(MAPPINGS) / sizeof(MAPPINGS[0]);

// four pieces, five levels, five variants each.
static_assert(MAPPING_COUNT == 4 * 5 * 5, "the silk armour set is 100 names");

// ---- the instruction we look for --------------------------------------------
// push imm32: a one byte opcode followed by the 32 bit constant it pushes.
static const BYTE     PUSH_IMM32 = 0x68;
static const uint32_t IMM_OFFSET = 1;   // the immediate starts past the opcode
static const uint32_t IMM_SIZE   = 4;   // and is 32 bits wide
static const uint32_t PUSH_LEN   = IMM_OFFSET + IMM_SIZE;

static_assert(IMM_SIZE == sizeof(uint32_t), "the immediate is not a uint32_t");

// calculates string length by finding the NUL termination byte
static uint32_t Length(const char* text)
{
    uint32_t n = 0;
    while (text[n]) {
        n++;
    }
    return n;
}

// representation of a section with start pointer and size
struct Section
{
    const BYTE* data;
    uint32_t    size;
};

// representation of a replace site with address to original name and pointer to
// the operand bytes where the actual replacement happens
struct Site
{
    uint32_t address;   // the address of the original name, in .rdata
    BYTE*    operand;   // the pointer to push imm32 operand bytes, in .text
};

// ---- image sections ---------------------------------------------------------

// checks if the given section has the name we expect
static bool SectionIs(const IMAGE_SECTION_HEADER* section, const char* name)
{
    const uint32_t length = Length(name);
    if (length > IMAGE_SIZEOF_SHORT_NAME) {
        return false;
    }

    for (uint32_t i = 0; i < IMAGE_SIZEOF_SHORT_NAME; i++) {
        const BYTE expected = (i < length) ? (BYTE)name[i] : 0;
        if (section->Name[i] != expected) {
            return false;
        }
    }
    return true;
}

// finds sections via their name
static bool FindSection(uint32_t base, const char* name, Section* out)
{
    const IMAGE_DOS_HEADER* dos = (const IMAGE_DOS_HEADER*)base;
    if (dos->e_magic != IMAGE_DOS_SIGNATURE) {
        return false;
    }

    const IMAGE_NT_HEADERS32* nt =
        (const IMAGE_NT_HEADERS32*)(base + (uint32_t)dos->e_lfanew);
    if (nt->Signature != IMAGE_NT_SIGNATURE) {
        return false;
    }

    const IMAGE_SECTION_HEADER* sections = IMAGE_FIRST_SECTION(nt);
    for (uint32_t i = 0; i < nt->FileHeader.NumberOfSections; i++) {
        if (SectionIs(&sections[i], name)) {
            out->data = (const BYTE*)(base + sections[i].VirtualAddress);
            out->size = sections[i].Misc.VirtualSize;
            return true;
        }
    }
    return false;
}

// ---- locating names and pushes ----------------------------------------------

// Finds the single address a name sits at in a section.
// -> must end with NUL termination
// -> byte before start must be NUL termination from previous entry
//    (unless it is the first one we check)
// -> compare byte by byte
// Must be bound by NUL termination bytes, which avoids partial matches.
//
// Returns 0 if the name is missing, or if it appears more than once and is
// therefore ambiguous.
static uint32_t FindUniqueName(const Section* rdata, const char* name)
{
    const uint32_t length = Length(name);
    uint32_t found = 0;

    if (length == 0 || length >= rdata->size) {
        return 0;
    }

    for (uint32_t i = 0; i + length < rdata->size; i++) {
        // check if previous byte is NUL termination from the previous entry
        // (unless it is the first one we check)
        if (i != 0 && rdata->data[i - 1] != 0) {
            continue;
        }
        // check if first byte matches and if expected end is a NUL termination
        if (rdata->data[i] != (BYTE)name[0] || rdata->data[i + length] != 0) {
            continue;
        }
        // compare byte by byte
        if (memcmp(rdata->data + i, name, length) != 0) {
            continue;
        }
        // a second occurrence makes the name ambiguous, so it has to fail
        // rather than be guessed at
        if (found != 0) {
            return 0;
        }
        found = (uint32_t)(rdata->data + i);
    }
    return found;
}

// scan .rdata section for the text we want to replace and store the address to
// find the push instruction with that address in the following step
static bool LocateNames(const Section* rdata, Site* sites)
{
    for (uint32_t m = 0; m < MAPPING_COUNT; m++) {
        sites[m].address = FindUniqueName(rdata, MAPPINGS[m].from);
        // stop and return if the name was not found or more than once
        if (sites[m].address == 0) {
            return false;
        }
    }
    return true;
}

// scan .text section for `push imm32 <address_to_replace>` and store the
// pointer to inject our address in the following step
static bool LocatePushes(const Section* text, Site* sites)
{
    if (text->size < PUSH_LEN) {
        return false;
    }

    // find lowest and highest address for optimization and set operand to null
    uint32_t low  = 0xFFFFFFFF;
    uint32_t high = 0x00000000;
    for (uint32_t m = 0; m < MAPPING_COUNT; m++) {
        sites[m].operand = 0;
        if (sites[m].address < low) {
            low = sites[m].address;
        }
        if (sites[m].address > high) {
            high = sites[m].address;
        }
    }

    const BYTE* last = text->data + text->size - PUSH_LEN;
    for (const BYTE* p = text->data; p <= last; p++) {
        // continue if there is no IMM32 push
        if (*p != PUSH_IMM32) {
            continue;
        }

        const uint32_t immAddress = *(const uint32_t*)(p + IMM_OFFSET);
        // continue if the address is outside the range of names we located
        if (immAddress < low || immAddress > high) {
            continue;
        }

        for (uint32_t m = 0; m < MAPPING_COUNT; m++) {
            // continue if the pushed address is not where this mapping's name sits
            if (sites[m].address != immAddress) {
                continue;
            }
            // stop and return if operand is already set
            if (sites[m].operand != 0) {
                return false;
            }
            // store operand address in our site
            sites[m].operand = (BYTE*)(p + IMM_OFFSET);
            break;
        }
    }

    for (uint32_t m = 0; m < MAPPING_COUNT; m++) {
        // stop and return if any operand is still null
        if (sites[m].operand == 0) {
            return false;
        }
    }
    return true;
}

// ---- patching ---------------------------------------------------------------
static bool WriteAll(const Site* sites)
{
    BYTE* low  = sites[0].operand;
    BYTE* high = sites[0].operand;
    // find boundaries to calculate size
    for (uint32_t m = 1; m < MAPPING_COUNT; m++) {
        if (sites[m].operand < low) {
            low  = sites[m].operand;
        }
        if (sites[m].operand > high) {
            high = sites[m].operand;
        }
    }
    const uint32_t span = (uint32_t)(high - low) + IMM_SIZE;

    DWORD oldProtection;
    if (!VirtualProtect(low, span, PAGE_EXECUTE_READWRITE, &oldProtection)) {
        return false;
    }

    for (uint32_t m = 0; m < MAPPING_COUNT; m++) {
        // write address of new value as operand
        *(uint32_t*)sites[m].operand = (uint32_t)MAPPINGS[m].to;
    }

    VirtualProtect(low, span, oldProtection, &oldProtection);
    FlushInstructionCache(GetCurrentProcess(), low, span);
    return true;
}

extern "C" __declspec(dllexport) BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason != DLL_PROCESS_ATTACH) {
        return TRUE;
    }

    const uint32_t base = (uint32_t)GetModuleHandle(NULL);

    Section text;
    Section rdata;
    if (!FindSection(base, ".text", &text) || !FindSection(base, ".rdata", &rdata)) {
        return TRUE;
    }

    // Strategy:
    // Find the name we want to replace in the .rdata section and collect the 
    // address.
    // Then find this address as the immediate of a push imm32 in the .text
    // section and replace the immediate with the address of our replacement
    // value.
    Site sites[MAPPING_COUNT];

    // Refuse to patch anything that is not the expected Cube.exe build.
    if (!LocateNames(&rdata, sites)) {
        return TRUE;
    }
    if (!LocatePushes(&text, sites)) {
        return TRUE;
    }

    WriteAll(sites);
    return TRUE;
}
