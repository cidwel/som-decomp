.setcpu "65816"
.segment "CODE"
.org $1A7F
map_control_0f1a7f:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
