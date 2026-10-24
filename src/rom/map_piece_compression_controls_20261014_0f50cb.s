.setcpu "65816"
.segment "CODE"
.org $50CB
map_control_0f50cb:
    .byte $E7 ; previous-row copy count
