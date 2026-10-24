.setcpu "65816"
.segment "CODE"
.org $D341
map_control_0ed341:
    .byte $DC ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
