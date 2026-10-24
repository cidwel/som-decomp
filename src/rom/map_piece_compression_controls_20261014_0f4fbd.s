.setcpu "65816"
.segment "CODE"
.org $4FBD
map_control_0f4fbd:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
