.setcpu "65816"
.segment "CODE"
.org $8A60
map_control_0d8a60:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
