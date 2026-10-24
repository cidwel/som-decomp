.setcpu "65816"
.segment "CODE"
.org $C889
map_control_0dc889:
    .byte $E8 ; backreference distance high bits
    .byte $CD ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $98 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $E7 ; row-distance/count
