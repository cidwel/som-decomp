.setcpu "65816"
.segment "CODE"
.org $BACC
map_control_0fbacc:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C3 ; same-value copy count/distance
