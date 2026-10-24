.setcpu "65816"
.segment "CODE"
.org $80F7
map_control_0f80f7:
    .byte $E4 ; previous-row copy count
