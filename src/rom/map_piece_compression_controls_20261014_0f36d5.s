.setcpu "65816"
.segment "CODE"
.org $36D5
map_control_0f36d5:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
