.setcpu "65816"
.segment "CODE"
.org $9EC1
map_control_0e9ec1:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
