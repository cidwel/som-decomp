.setcpu "65816"
.segment "CODE"
.org $3315
map_control_0e3315:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
