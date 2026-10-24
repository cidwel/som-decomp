.setcpu "65816"
.segment "CODE"
.org $ED64
map_control_0ded64:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
