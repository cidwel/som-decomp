; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-map-contacts.md.
.setcpu "65816"
.smart
.a8
.i16

public_three_boss_party_contact_jump = $C20015
routine_01e76d = $1E76D
scan_active_map_contact_pool_for_one_hero = $CDCD

.segment "CODE"
.org $CD4E
scan_three_heroes_against_map_contacts_and_publish_first_event:
    rep #$20
    lda $C0
    lsr
    sta $18
    lda $C2
    lsr
    sta $1A
    stz $0E
    rep #$10
    sep #$20
    bit $FF
    bmi scan_three_heroes_against_map_contacts_and_publish_first_event_c1cd72
    bvs scan_three_heroes_against_map_contacts_and_publish_first_event_c1cd72
    bit $F1
    bmi scan_three_heroes_against_map_contacts_and_publish_first_event_c1cd72
    bit $5C
    bpl scan_three_heroes_against_map_contacts_and_publish_first_event_c1cd73
    jsl f:public_three_boss_party_contact_jump
scan_three_heroes_against_map_contacts_and_publish_first_event_c1cd72:
    rtl
scan_three_heroes_against_map_contacts_and_publish_first_event_c1cd73:
    lda a:$CF01
    lsr
    bcs scan_three_heroes_against_map_contacts_and_publish_first_event_c1cd72
    .a8
    lda #$11
    sta $51
    .i16
    ldx #$0000
    jsr scan_active_map_contact_pool_for_one_hero
    .i16
    ldx #$0200
    jsr scan_active_map_contact_pool_for_one_hero
    .i16
    ldx #$0400
    jsr scan_active_map_contact_pool_for_one_hero
    sep #$20
    lda $D0
    bne scan_three_heroes_against_map_contacts_and_publish_first_event_c1cdcc
    ldy $0E
    beq scan_three_heroes_against_map_contacts_and_publish_first_event_c1cdcc
    .i16
    cpy #$8000
    ldx $1C
    ldy $1E
    stx $D4
    sty $3A
    bcs scan_three_heroes_against_map_contacts_and_publish_first_event_c1cdc1
    lda a:$E010,X
    .a8
    cmp #$02
    bcc scan_three_heroes_against_map_contacts_and_publish_first_event_c1cdb1
    .a8
    eor #$80
    bra scan_three_heroes_against_map_contacts_and_publish_first_event_c1cdb3
scan_three_heroes_against_map_contacts_and_publish_first_event_c1cdb1:
    .a8
    eor #$01
scan_three_heroes_against_map_contacts_and_publish_first_event_c1cdb3:
    sta a:$E010,Y
    rep #$20
    .a16
    lda #$0000
    sta a:$E006,Y
    sta a:$E008,Y
scan_three_heroes_against_map_contacts_and_publish_first_event_c1cdc1:
    rep #$20
    lda $0E
    .a16
    and #$0FFF
    jsl f:routine_01e76d
scan_three_heroes_against_map_contacts_and_publish_first_event_c1cdcc:
    rtl
