.setcpu "65816"
.segment "CODE"
.org $4A55
map_control_0f4a55:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
