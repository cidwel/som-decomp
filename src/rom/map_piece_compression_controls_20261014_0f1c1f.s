.setcpu "65816"
.segment "CODE"
.org $1C1F
map_control_0f1c1f:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count
