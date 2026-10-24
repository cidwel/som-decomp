.setcpu "65816"
.segment "CODE"
.org $611C
map_control_0c611c:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
