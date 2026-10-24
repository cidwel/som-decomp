; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

apply_packed_appearance_attribute_adjustments = $4AFF
cap_actor_appearance_word_and_byte_attributes = $4BF9
classify_actor_appearance_from_sprite = $47DD
derive_actor_appearance_palette_attributes = $49AA
load_actor_base_attributes_for_appearance = $474F
prepare_actor_appearance_context = $4518
prepare_actor_appearance_table_pointers = $4860
read_appearance_level_and_party_charge = $48E6
reduce_and_clamp_actor_appearance_attributes = $4BBE
refresh_actor_appearance_special_sprite = $45E6
reorder_actor_attribute_bit_pairs = $4A53
restore_actor_appearance_context_long = $4576

.segment "CODE"
.org $457C
refresh_actor_appearance_native:
    phd
    phb
    php
    jsr prepare_actor_appearance_context
    jsr classify_actor_appearance_from_sprite
    lda a:$E1FB,X
    .a8
    bit #$30
    beq refresh_actor_appearance_native_c0458f
    jmp restore_actor_appearance_context_long
refresh_actor_appearance_native_c0458f:
    lda a:$E1FA,X
    .a8
    ora #$04
    sta a:$E1FA,X
    lda a:$E1FB,X
    .a8
    bit #$40
    bne refresh_actor_appearance_special_sprite
    jsr read_appearance_level_and_party_charge
    jsr load_actor_base_attributes_for_appearance
    jsr prepare_actor_appearance_table_pointers
    jsr apply_packed_appearance_attribute_adjustments
    jsr reduce_and_clamp_actor_appearance_attributes
    jsr derive_actor_appearance_palette_attributes
    phy
    .i16
    ldy #$1006
    lda [$C0],Y
    ply
    sta a:$E196,X
    phy
    .i16
    ldy #$100B
    lda [$C0],Y
    ply
    sta a:$E1F7,X
    jsr reorder_actor_attribute_bit_pairs
    lda a:$E1AB,X
    .a8
    ora #$12
    sta a:$E1AB,X
    jsr cap_actor_appearance_word_and_byte_attributes
    plp
    plb
    pld
    rtl
