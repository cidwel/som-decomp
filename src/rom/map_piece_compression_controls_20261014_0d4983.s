.setcpu "65816"
.segment "CODE"
.org $4983
map_control_0d4983:
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
