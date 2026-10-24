.setcpu "65816"
.segment "CODE"
.org $A842
map_control_0fa842:
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
