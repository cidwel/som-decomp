.setcpu "65816"
.segment "CODE"
.org $7031
map_control_0f7031:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
