.setcpu "65816"
.segment "CODE"
.org $FB15
map_control_0cfb15:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E5 ; previous-row copy count
