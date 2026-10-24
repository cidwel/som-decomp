.setcpu "65816"
.segment "CODE"
.org $3AEB
map_control_0f3aeb:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
