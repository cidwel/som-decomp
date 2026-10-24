.setcpu "65816"
.segment "CODE"
.org $C9A9
map_control_0dc9a9:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count
