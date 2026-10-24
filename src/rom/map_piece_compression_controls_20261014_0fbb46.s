.setcpu "65816"
.segment "CODE"
.org $BB46
map_control_0fbb46:
    .byte $C6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
