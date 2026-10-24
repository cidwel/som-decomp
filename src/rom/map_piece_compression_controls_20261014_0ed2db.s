.setcpu "65816"
.segment "CODE"
.org $D2DB
map_control_0ed2db:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
