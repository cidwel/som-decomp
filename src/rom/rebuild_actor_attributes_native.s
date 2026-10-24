; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

apply_packed_appearance_attribute_adjustments = $4AFF
apply_three_armor_attribute_flags = $4B7D
cap_actor_appearance_word_and_byte_attributes = $4BF9
classify_actor_appearance_from_sprite = $47DD
combine_hero_armor_element_resistance = $4A2D
derive_actor_appearance_palette_attributes = $49AA
derive_hero_armor_defenses_and_immunity = $4A75
derive_hero_weapon_level_accuracy = $4A0C
load_hero_level_attributes_and_controller_adjustments = $464F
prepare_actor_appearance_context = $4518
prepare_actor_appearance_table_pointers = $4860
read_appearance_level_and_party_charge = $48E6
reduce_and_clamp_actor_appearance_attributes = $4BBE
restore_actor_appearance_context_long = $4576
refresh_actor_appearance_attributes_body = $4597

.segment "CODE"
.org $4530
rebuild_actor_attributes_native:
    phd
    phb
    php
    jsr prepare_actor_appearance_context
    jsr classify_actor_appearance_from_sprite
    lda a:$E1FB,X
    .a8
    bit #$20
    beq rebuild_actor_attributes_native_c04543
    jmp restore_actor_appearance_context_long
rebuild_actor_attributes_native_c04543:
    lda a:$E1FB,X
    bmi rebuild_actor_attributes_native_c0454b
    jmp refresh_actor_appearance_attributes_body
rebuild_actor_attributes_native_c0454b:
    jsr load_hero_level_attributes_and_controller_adjustments
    jsr prepare_actor_appearance_table_pointers
    jsr read_appearance_level_and_party_charge
    jsr apply_three_armor_attribute_flags
    jsr apply_packed_appearance_attribute_adjustments
    jsr reduce_and_clamp_actor_appearance_attributes
    jsr derive_actor_appearance_palette_attributes
    jsr derive_hero_weapon_level_accuracy
    jsr combine_hero_armor_element_resistance
    jsr derive_hero_armor_defenses_and_immunity
    jsr cap_actor_appearance_word_and_byte_attributes
    phy
    .i16
    ldy #$100B
    lda [$C0],Y
    ply
    sta a:$E1F7,X
