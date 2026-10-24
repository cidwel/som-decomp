.setcpu "65816"
.segment "CODE"
.org $78ED
map_control_0e78ed:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
