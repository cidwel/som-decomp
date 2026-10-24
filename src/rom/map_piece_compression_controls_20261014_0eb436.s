.setcpu "65816"
.segment "CODE"
.org $B436
map_control_0eb436:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
