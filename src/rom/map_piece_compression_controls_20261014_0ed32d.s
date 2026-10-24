.setcpu "65816"
.segment "CODE"
.org $D32D
map_control_0ed32d:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
