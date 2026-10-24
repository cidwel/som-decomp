; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-hero-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

clear_actor_identity_attribute_record = $4E31
jump_inventory_insert_with_explicit_hero_owner = $C06423
load_hero_level_attributes_and_controller_adjustments = $464F
rebuild_actor_attributes_native = $C04530

.segment "CODE"
.org $4D72
initialize_hero_identity_health_equipment_and_inventory:
    phd
    phb
    php
    rep #$30
    .a16
    lda #$0300
    tcd
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    stx $BD
    jsr clear_actor_identity_attribute_record
    ldx $BD
    sep #$20
    lda $BE
    lsr
    sta $BA
    clc
    .a8
    adc #$80
    sta a:$E180,X
    sta a:$E1E7,X
    jsr load_hero_level_attributes_and_controller_adjustments
    rep #$20
    lda a:$E184,X
    sta a:$E182,X
    .a16
    lda #$0000
    sep #$20
    lda a:$E187,X
    sta a:$E186,X
    .a8
    lda #$07
    sta a:$E1FA,X
    lda $BA
    asl
    tax
    rep #$20
    lda f:$C04E2B,X
    sta $B4
    tax
    ldy $BD
    sep #$20
    .a8
    lda #$80
    sta a:$E1FB,Y
    lda f:$C00000,X
    sta a:$E1E0,Y
    lda f:$C00001,X
    sta a:$E1E1,Y
    lda f:$C00002,X
    sta a:$E1E2,Y
    lda f:$C00003,X
    sta a:$E1E3,Y
    sta a:$E1E8,Y
    inc $BA
    lda f:$C00000,X
    beq initialize_hero_identity_health_equipment_and_inventory_c04df6
    ldx $BA
    jsl f:jump_inventory_insert_with_explicit_hero_owner
initialize_hero_identity_health_equipment_and_inventory_c04df6:
    ldx $B4
    lda f:$C00001,X
    beq initialize_hero_identity_health_equipment_and_inventory_c04e04
    ldx $BA
    jsl f:jump_inventory_insert_with_explicit_hero_owner
initialize_hero_identity_health_equipment_and_inventory_c04e04:
    ldx $B4
    lda f:$C00002,X
    beq initialize_hero_identity_health_equipment_and_inventory_c04e12
    ldx $BA
    jsl f:jump_inventory_insert_with_explicit_hero_owner
initialize_hero_identity_health_equipment_and_inventory_c04e12:
    ldx $B4
    lda f:$C00003,X
    clc
    .a8
    adc #$80
    ldx $BA
    jsl f:jump_inventory_insert_with_explicit_hero_owner
    ldx $BD
    jsl f:rebuild_actor_attributes_native
    plp
    plb
    pld
    rtl
