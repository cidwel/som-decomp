.setcpu "65816"
.segment "CODE"
.org $2370
map_control_0e2370:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
