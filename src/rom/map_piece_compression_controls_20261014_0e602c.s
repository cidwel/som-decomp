.setcpu "65816"
.segment "CODE"
.org $602C
map_control_0e602c:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
