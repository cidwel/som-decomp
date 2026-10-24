.setcpu "65816"
.segment "CODE"
.org $6249
map_control_0f6249:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
