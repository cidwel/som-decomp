.setcpu "65816"
.segment "CODE"
.org $36E8
map_control_0f36e8:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
