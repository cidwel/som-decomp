.setcpu "65816"
.segment "CODE"
.org $DCBD
map_control_0fdcbd:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
