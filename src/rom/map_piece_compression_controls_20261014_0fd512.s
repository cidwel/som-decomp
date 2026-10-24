.setcpu "65816"
.segment "CODE"
.org $D512
map_control_0fd512:
    .byte $E5 ; previous-row copy count
