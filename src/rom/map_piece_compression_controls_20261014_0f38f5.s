.setcpu "65816"
.segment "CODE"
.org $38F5
map_control_0f38f5:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
