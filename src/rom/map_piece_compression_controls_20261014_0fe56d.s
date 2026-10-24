.setcpu "65816"
.segment "CODE"
.org $E56D
map_control_0fe56d:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
