.setcpu "65816"
.segment "CODE"
.org $0A5A
map_control_0f0a5a:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
