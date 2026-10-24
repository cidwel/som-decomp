.setcpu "65816"
.segment "CODE"
.org $FD05
; Four native mode6 callbacks; original execution covers every state.
.word $FC44, $FCA7, $FCD3, $FCF5
