.setcpu "65816"
.segment "CODE"
.org $0CF0
map_control_0f0cf0:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
