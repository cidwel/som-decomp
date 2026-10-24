.setcpu "65816"
.segment "CODE"
.org $FBB8
map_control_0dfbb8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
