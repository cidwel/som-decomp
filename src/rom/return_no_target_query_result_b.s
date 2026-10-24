; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-target-status-queries.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0A43
return_no_target_query_result_b:
    .a16
    lda #$FFFF
    rts
