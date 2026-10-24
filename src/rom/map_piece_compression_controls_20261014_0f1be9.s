.setcpu "65816"
.segment "CODE"
.org $1BE9
map_control_0f1be9:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
