.setcpu "65816"
.segment "CODE"
.org $5BDF
map_control_0f5bdf:
    .byte $E4 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
