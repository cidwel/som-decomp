.setcpu "65816"
.segment "CODE"
.org $E4E2
map_control_0de4e2:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
