; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-chest-reward.md.
.setcpu "65816"
.smart
.a8
.i16

add_or_spend_party_gold_with_saved_context = $C039CF
jump_native_inventory_insert_command = $C06420
publish_chest_gold_amount_notice = $C058C8
publish_full_chest_inventory_notice = $C058F1
publish_successful_chest_inventory_notice = $C058DB
random_byte_long_wrapper = $C0389C

.segment "CODE"
.org $E12C
select_chest_gold_item_or_weapon_orb_and_publish:
    lda f:$D03A52,X
    sta $AC
    .a8
    and #$38
    lsr
    lsr
    lsr
    sta $A4
    jsl f:random_byte_long_wrapper
    .a8
    and #$3F
    cmp $A4
    php
    lda $AC
    .a8
    and #$C0
    bne select_chest_gold_item_or_weapon_orb_and_publish_c8e14b
    jmp select_chest_gold_item_or_weapon_orb_and_publish_c8e1cc
select_chest_gold_item_or_weapon_orb_and_publish_c8e14b:
    .a8
    cmp #$40
    beq select_chest_gold_item_or_weapon_orb_and_publish_c8e162
    .a8
    cmp #$80
    beq select_chest_gold_item_or_weapon_orb_and_publish_c8e171
    plp
    bcc select_chest_gold_item_or_weapon_orb_and_publish_c8e15c
    lda f:$D03A53,X
    bra select_chest_gold_item_or_weapon_orb_and_publish_c8e17e
select_chest_gold_item_or_weapon_orb_and_publish_c8e15c:
    lda f:$D03A54,X
    bra select_chest_gold_item_or_weapon_orb_and_publish_c8e1d9
select_chest_gold_item_or_weapon_orb_and_publish_c8e162:
    plp
    bcc select_chest_gold_item_or_weapon_orb_and_publish_c8e16b
    lda f:$D03A53,X
    bra select_chest_gold_item_or_weapon_orb_and_publish_c8e17e
select_chest_gold_item_or_weapon_orb_and_publish_c8e16b:
    lda f:$D03A54,X
    bra select_chest_gold_item_or_weapon_orb_and_publish_c8e17e
select_chest_gold_item_or_weapon_orb_and_publish_c8e171:
    plp
    bcc select_chest_gold_item_or_weapon_orb_and_publish_c8e17a
    lda f:$D03A53,X
    bra select_chest_gold_item_or_weapon_orb_and_publish_c8e1d9
select_chest_gold_item_or_weapon_orb_and_publish_c8e17a:
    lda f:$D03A54,X
select_chest_gold_item_or_weapon_orb_and_publish_c8e17e:
    sta $A4
    .a8
    cmp #$00
    bmi select_chest_gold_item_or_weapon_orb_and_publish_c8e199
    jsl f:jump_native_inventory_insert_command
    lda a:$CF0F
    bne select_chest_gold_item_or_weapon_orb_and_publish_c8e1c0
    lda $A4
    clc
    .a8
    adc #$48
    sta $A6
    jsl f:publish_successful_chest_inventory_notice
    rts
select_chest_gold_item_or_weapon_orb_and_publish_c8e199:
    ldx $85
    sec
    .a8
    sbc #$80
    sta a:$E1C9,X
    rep #$20
    .a16
    and #$00FF
    sep #$20
    tay
    lda a:$CFC0,Y
    sta $A6
    lda a:$CFB8,Y
    inc
    cmp $A6
    bcc select_chest_gold_item_or_weapon_orb_and_publish_c8e1ba
    .a8
    lda #$40
    bra select_chest_gold_item_or_weapon_orb_and_publish_c8e17e
select_chest_gold_item_or_weapon_orb_and_publish_c8e1ba:
    .a8
    lda #$08
    sta a:$E1C8,X
    rts
select_chest_gold_item_or_weapon_orb_and_publish_c8e1c0:
    lda $A4
    clc
    .a8
    adc #$48
    sta $A6
    jsl f:publish_full_chest_inventory_notice
    rts
select_chest_gold_item_or_weapon_orb_and_publish_c8e1cc:
    plp
    bcc select_chest_gold_item_or_weapon_orb_and_publish_c8e1d5
    lda f:$D03A53,X
    bra select_chest_gold_item_or_weapon_orb_and_publish_c8e1d9
select_chest_gold_item_or_weapon_orb_and_publish_c8e1d5:
    lda f:$D03A54,X
select_chest_gold_item_or_weapon_orb_and_publish_c8e1d9:
    rep #$20
    .a16
    and #$00FF
    phx
    pha
    jsl f:add_or_spend_party_gold_with_saved_context
    pla
    plx
    sep #$20
    jsl f:publish_chest_gold_amount_notice
    rts
