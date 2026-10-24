.setcpu "65816"
.segment "CODE"
.org $0D6C
map_control_0c0d6c:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
