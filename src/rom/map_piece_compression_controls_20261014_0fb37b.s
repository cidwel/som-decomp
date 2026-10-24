.setcpu "65816"
.segment "CODE"
.org $B37B
map_control_0fb37b:
    .byte $EE ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
