.setcpu "65816"
.segment "CODE"
.org $0ACE
map_control_0d0ace:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
