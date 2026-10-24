.setcpu "65816"
.segment "CODE"
.org $08DF
map_control_0f08df:
    .byte $E7 ; previous-row copy count
