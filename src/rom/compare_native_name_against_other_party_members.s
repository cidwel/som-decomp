; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-name-helpers.md.
.setcpu "65816"
.smart
.a8
.i16

compare_twelve_native_party_name_bytes = $5181

.segment "CODE"
.org $5162
compare_native_name_against_other_party_members:
    .a8
    lda #$03
    sta a:$A175
compare_native_name_against_other_party_members_c75167:
    lda a:$A175
    dec
    cmp a:$A22B
    beq compare_native_name_against_other_party_members_c7517b
    stz a:$A171
    jsr compare_twelve_native_party_name_bytes
    lda a:$A171
    beq compare_native_name_against_other_party_members_c75180
compare_native_name_against_other_party_members_c7517b:
    dec a:$A175
    bne compare_native_name_against_other_party_members_c75167
compare_native_name_against_other_party_members_c75180:
    rtl
