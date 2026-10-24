.setcpu "65816"
.segment "CODE"
.org $4737
map_control_0c4737:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
