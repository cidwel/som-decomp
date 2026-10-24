; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-map-contacts.md.
.setcpu "65816"
.smart
.a8
.i16

compare_two_packed_contact_hitboxes = $D42A
record_contact_presentation_byte_and_volume = $D285

.segment "CODE"
.org $D14A
compare_native_contact_hitboxes_and_publish_collision_flags:
    rep #$20
    lda a:$E0C2,X
    bne compare_native_contact_hitboxes_and_publish_collision_flags_c1d154
    brl compare_native_contact_hitboxes_and_publish_collision_flags_c1d1f8
compare_native_contact_hitboxes_and_publish_collision_flags_c1d154:
    sta $16
    lda a:$E0C0,X
    sta $14
    sep #$20
    lda $50
    .a8
    and #$F0
    and a:$E05A,X
    bne compare_native_contact_hitboxes_and_publish_collision_flags_c1d18a
    rep #$20
    lda a:$E0C2,Y
    beq compare_native_contact_hitboxes_and_publish_collision_flags_c1d18a
    sta $12
    lda a:$E0C0,Y
    sta $10
    jsr compare_two_packed_contact_hitboxes
    bcs compare_native_contact_hitboxes_and_publish_collision_flags_c1d18a
    sep #$20
    .a8
    lda #$80
    jsr record_contact_presentation_byte_and_volume
    lda $50
    .a8
    and #$F0
    ora a:$E05A,X
    sta a:$E05A,X
compare_native_contact_hitboxes_and_publish_collision_flags_c1d18a:
    sep #$20
    lda $50
    .a8
    and #$0F
    and a:$E05A,X
    bne compare_native_contact_hitboxes_and_publish_collision_flags_c1d1c9
    rep #$20
    lda a:$E0CA,Y
    beq compare_native_contact_hitboxes_and_publish_collision_flags_c1d1c9
    sta $12
    lda a:$E0C8,Y
    sta $10
    jsr compare_two_packed_contact_hitboxes
    bcs compare_native_contact_hitboxes_and_publish_collision_flags_c1d1c9
    sep #$20
    .a8
    lda #$01
    .i16
    cpx #$0000
    beq compare_native_contact_hitboxes_and_publish_collision_flags_c1d1b9
    inc
    .i16
    cpx #$0200
    beq compare_native_contact_hitboxes_and_publish_collision_flags_c1d1b9
    .a8
    lda #$04
compare_native_contact_hitboxes_and_publish_collision_flags_c1d1b9:
    ora a:$E059,Y
    sta a:$E059,Y
    lda $50
    .a8
    and #$0F
    ora a:$E05A,X
    sta a:$E05A,X
compare_native_contact_hitboxes_and_publish_collision_flags_c1d1c9:
    sep #$20
    lda $50
    .a8
    and #$F0
    and a:$E05A,X
    bne compare_native_contact_hitboxes_and_publish_collision_flags_c1d1f8
    rep #$20
    lda a:$E0CE,Y
    beq compare_native_contact_hitboxes_and_publish_collision_flags_c1d1f8
    sta $12
    lda a:$E0CC,Y
    sta $10
    jsr compare_two_packed_contact_hitboxes
    bcs compare_native_contact_hitboxes_and_publish_collision_flags_c1d1f8
    sep #$20
    .a8
    lda #$81
    jsr record_contact_presentation_byte_and_volume
    lda $50
    .a8
    and #$F0
    ora a:$E05A,X
    sta a:$E05A,X
compare_native_contact_hitboxes_and_publish_collision_flags_c1d1f8:
    rep #$20
    lda $06
    .a16
    eor #$8080
    sta $06
    lda a:$E0C2,Y
    beq compare_native_contact_hitboxes_and_publish_collision_flags_c1d27b
    sta $16
    lda a:$E0C0,Y
    sta $14
    sep #$20
    lda $51
    .a8
    and #$0F
    and a:$E05A,Y
    bne compare_native_contact_hitboxes_and_publish_collision_flags_c1d24c
    rep #$20
    lda a:$E0CA,X
    beq compare_native_contact_hitboxes_and_publish_collision_flags_c1d24c
    sta $12
    lda a:$E0C8,X
    sta $10
    jsr compare_two_packed_contact_hitboxes
    bcs compare_native_contact_hitboxes_and_publish_collision_flags_c1d24c
    sep #$20
    .a8
    lda #$01
    .i16
    cpy #$0600
    beq compare_native_contact_hitboxes_and_publish_collision_flags_c1d23c
    inc
    .i16
    cpy #$0800
    beq compare_native_contact_hitboxes_and_publish_collision_flags_c1d23c
    .a8
    lda #$04
compare_native_contact_hitboxes_and_publish_collision_flags_c1d23c:
    ora a:$E059,X
    sta a:$E059,X
    lda $51
    .a8
    and #$0F
    ora a:$E05A,Y
    sta a:$E05A,Y
compare_native_contact_hitboxes_and_publish_collision_flags_c1d24c:
    sep #$20
    lda $51
    .a8
    and #$F0
    and a:$E05A,Y
    bne compare_native_contact_hitboxes_and_publish_collision_flags_c1d27b
    rep #$20
    lda a:$E0CE,X
    beq compare_native_contact_hitboxes_and_publish_collision_flags_c1d27b
    sta $12
    lda a:$E0CC,X
    sta $10
    jsr compare_two_packed_contact_hitboxes
    bcs compare_native_contact_hitboxes_and_publish_collision_flags_c1d27b
    sep #$20
    .a8
    lda #$81
    jsr record_contact_presentation_byte_and_volume
    lda $51
    .a8
    and #$F0
    ora a:$E05A,Y
    sta a:$E05A,Y
compare_native_contact_hitboxes_and_publish_collision_flags_c1d27b:
    rep #$20
    lda $06
    .a16
    eor #$8080
    sta $06
    rts
