.setcpu "65816"
.segment "CODE"
.org $D25A
map_control_0ed25a:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
