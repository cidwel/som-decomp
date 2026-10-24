.setcpu "65816"
.segment "CODE"
.org $2ABA
map_control_0f2aba:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E4 ; previous-row copy count
