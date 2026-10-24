.setcpu "65816"
.segment "CODE"
.org $ED99
map_control_0eed99:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
